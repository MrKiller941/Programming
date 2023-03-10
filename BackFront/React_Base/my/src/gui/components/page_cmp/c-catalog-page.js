import React, { useEffect, useState } from "react";
import Template from "./template";

import CtgElement from "./../../complex_cmp/c-ctg-element/c-ctg-element";
import BasketPanel from "./../../complex_cmp/c-basket-panel/c-basket-panel";

import { RouterFactory } from "./../../../componentRouter/componentRouter";
import { UserFactory } from "./../../../classes/user";
import IOrouter from "./../../../IOrouter/IOrouter";

const Catalog = () => {
  const [elements, setElements] = useState([]);
  const [busket, setBusket] = useState(null);

  useEffect(() => {
    const user = UserFactory.createInstance();
    IOrouter.getCatalog(user.getLogin(), user.getPassword())
      .then((res) => {
        setElements(res);
      })
      .catch((err) => {
        console.log("Error getting catalog: " + err);
      });
  }, []);

  const handleAddButtonClick = () => {
    const router = RouterFactory.createInstance();
    router.go("c-addprod-page");
  };

  const handleDelButtonClick = () => {
    const router = RouterFactory.createInstance();
    router.go("c-delprod-page");
  };

  const handleButtonClick = (index) => {
    const elem = elements[index];
    busket.addAttributeAtBusket(
      index,
      elem.id,
      elem.medic_names,
      elem.img,
      elem.medic_cost
    );
  };

  return (
    <Template
      onAddButtonClick={handleAddButtonClick}
      onDelButtonClick={handleDelButtonClick}
    >
      <BasketPanel ref={(node) => setBusket(node)} />
      <div className="catalog">
        {elements.map((elem, index) => (
          <CtgElement
            key={elem.id}
            prod_id={elem.id}
            name={elem.medic_names}
            desc={elem.medic_count}
            cost={elem.medic_cost}
            src={elem.img}
            onButtonClick={() => handleButtonClick(index)}
          />
        ))}
      </div>
    </Template>
  );
};

export default Catalog;

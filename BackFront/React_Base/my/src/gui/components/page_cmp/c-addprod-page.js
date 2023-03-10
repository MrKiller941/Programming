import React, { useEffect } from 'react';
import template from './template.js';
import CButton from './../../simple_cmp/c-button/c-button.js';
import CLabel from './../../simple_cmp/c-label/c-label.js';
import { RouterFactory } from './../../../componentRouter/componentRouter.js';
import IOrouter from './../../../IOrouter/IOrouter.js';

const CtAddPage = () => {
  useEffect(() => {
    const addButton = document.querySelector('.panel .bt');
    addButton.addEventListener('click', listenerAdd);

    const backButton = document.querySelector('.panel .btBack');
    backButton.addEventListener('click', listenerBack);

    return () => {
      addButton.removeEventListener('click', listenerAdd);
      backButton.removeEventListener('click', listenerBack);
    };
  }, []);

  const listenerAdd = (event) => {
    event.stopPropagation();
    const panel = document.querySelector('.panel');
    const name = panel.querySelector('.nm .name').getValue();
    const cost = panel.querySelector('.cs .cost').getValue();
    const img = panel.querySelector('.im .img').getValue();
    const count = panel.querySelector('.ct .count').getValue();

    IOrouter.postNewProduct(name, cost, count, img)
      .then(() => {
        panel.querySelector('.message').innerHTML = '<br> Продукт успешно добавлен в каталог.';
      })
      .catch((err) => {
        panel.querySelector('.message').innerHTML = '<br> Ошибка добавления в каталог.';
        console.log('Error to adding new product: ' + err);
      });
  };

  const listenerBack = (event) => {
    event.stopPropagation();
    const router = RouterFactory.createInstance();
    router.go('c-catalog-page');
  };

  return <div dangerouslySetInnerHTML={{ __html: template }} />;
};

export default CtAddPage;

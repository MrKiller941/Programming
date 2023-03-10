import React from 'react';

function CatalogPage({ onAddProduct, onDeleteProduct }) {
  return (
    <div style={{ position: 'absolute', top: '4.5vw', left: '20vw' }}>
      <BasketPanel />
      <button className="addProd" onClick={onAddProduct}>Добавить продукт</button>
      <button className="delProd" onClick={onDeleteProduct}>Удалить продукт</button>
      <div className="catalog"></div>
    </div>
  );
}

function BasketPanel() {
  return (
    <c-basket-panel className="busket"></c-basket-panel>
  );
}

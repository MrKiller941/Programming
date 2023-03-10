import React from 'react';

function FormPanel({ onSubmit, onBack }) {
  return (
    <ul className="panel" style={{ position: 'absolute', marginLeft: '40%', marginTop: '65px', listStyleType: 'none' }}>
      <li className="nm">Название:<br/><c-textbar className="name" /></li>
      <li className="bt"><c-button value="Отправить" onClick={onSubmit} /></li>
      <li className="btBack"><c-button value="Назад" onClick={onBack} /></li>
      <div className="message"></div>
    </ul>
  );
}

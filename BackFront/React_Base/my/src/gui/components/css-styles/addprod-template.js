import React from 'react';

function Panel({ onSend, onBack }) {
  return (
    <ul style={{ position: 'absolute', marginLeft: '40%', marginTop: '65px', listStyleType: 'none' }}>
      <li className="nm">Название:<br /><input type="text" className="name" /></li>
      <li className="cs">Стоимость:<br /><input type="text" className="cost" /></li>
      <li className="im">Ссылка на изображение:<br /><input type="text" className="img" /></li>
      <li className="ct">Количество:<br /><input type="text" className="count" /></li>
      <li className="bt"><button onClick={onSend}>Отправить</button></li>
      <li className="btBack"><button onClick={onBack}>Назад</button></li>
      <div className="message"></div>
    </ul>
  );
}


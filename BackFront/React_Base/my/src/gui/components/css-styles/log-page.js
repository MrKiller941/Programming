import React from 'react';

function LoginPage({ onLoginClick, onRegisterClick }) {
  return (
    <div align="center" className="lpage">
      <c-log-panel id="c-log-panel" className="logPanel"></c-log-panel>
      <c-button value="Войти" className="logButton" onClick={onLoginClick}></c-button>
      <c-button value="Регистрация" className="regButton" onClick={onRegisterClick}></c-button>
    </div>
  );
}

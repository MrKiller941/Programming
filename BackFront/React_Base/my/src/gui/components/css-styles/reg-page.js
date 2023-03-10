import React from 'react';

function RegistrationPage() {
  return (
    <div align="center" className="regstr">
      <c-label value="Регистрация"></c-label>
      <br />
      <br />
      <c-label value="Логин"></c-label>
      <c-textbar className="login_bar"></c-textbar>

      <c-label value="Пароль"></c-label>
      <c-textbar className="password_bar"></c-textbar>
    </div>
  );
}

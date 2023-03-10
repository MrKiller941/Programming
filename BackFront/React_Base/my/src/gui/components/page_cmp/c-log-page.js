import { useState } from 'react';
import LogPanel from './../../complex_cmp/c-log-panel/c-log-panel.js';
import Button from './../../simple_cmp/c-button/c-button.js';
import { UserFactory } from './../../../classes/user.js';
import { RouterFactory } from './../../../componentRouter/componentRouter.js';
import IOrouter from './../../../IOrouter/IOrouter.js';

function CPLogin() {
  const [login, setLogin] = useState('');
  const [password, setPassword] = useState('');

  const auth = (event) => {
    event.stopPropagation();
    let user = UserFactory.createInstance();
    user.setLogin(login);
    user.setPassword(password);
    let router = RouterFactory.createInstance();

    IOrouter.signIn(user.getLogin(), user.getPassword())
      .then((res) => {
        user.setPassword(res);
        router.go('c-catalog-page');
      })
      .catch((err) => {
        console.log('Error authorisation: ' + err);
        router.go('c-log-page');
      });
  };

  const goReg = (event) => {
    event.stopPropagation();
    let router = RouterFactory.createInstance();
    router.go('c-reg-page');
  };

  return (
    <div className="lpage">
      <LogPanel
        onChangeLogin={(value) => setLogin(value)}
        onChangePassword={(value) => setPassword(value)}
      />
      <Button onClick={auth} className="logButton" label="Log in" />
      <Button onClick={goReg} className="regButton" label="Register" />
    </div>
  );
}

export default CPLogin;

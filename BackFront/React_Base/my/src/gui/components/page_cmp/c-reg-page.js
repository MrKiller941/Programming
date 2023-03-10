import React from 'react';

import template from './template.js';
import CRegPanel from './../../complex_cmp/c-reg-panel/c-reg-panel.js';
import CLogPanel from './../../complex_cmp/c-log-panel/c-log-panel.js';
import CButton from './../../simple_cmp/c-button/c-button.js';

import { UserFactory } from './../../../classes/user.js';
import { RouterFactory } from './../../../componentRouter/componentRouter.js';
import IOrouter from './../../../IOrouter/IOrouter.js';

class CRegPage extends React.Component {
  constructor(props) {
    super(props);
    this.state = {};
  }

  componentDidMount() {
    this._render();
  }

  componentWillUnmount() {}

  static get observedAttributes() {
    return [];
  }

  attributeChangedCallback(attr, prev, next) {
    this._render();
  }

  _reg(event) {
    event.stopPropagation();
    let user = UserFactory.createInstance();

    user.setLogin(this.shadowRoot.querySelector('.rpage').querySelector('.rpanel').getLogin());
    user.setPassword(this.shadowRoot.querySelector('.rpage').querySelector('.rpanel').getPassword());
    let router = RouterFactory.createInstance();
    IOrouter.signUp(user.getLogin(), user.getPassword())
      .then((res) => {
        router.go('c-log-page');
      })
      .catch((err) => {
        console.log('Error registration: ' + err);
        router.go('c-reg-page');
      });
  }

  _goAuth(event) {
    event.stopPropagation();
    let router = RouterFactory.createInstance();
    router.go('c-log-page');
  }

  _render() {
    if (!this.ownerDocument.defaultView) return;
    return (
      <div className="c-reg-page">
        {/* template function call */}
        {template(this)}
        <CRegPanel ref={(r) => (this.rpanel = r)} />
        <CButton
          className="sendBtn"
          onClick={(event) => {
            this._reg(event);
          }}
        />
        <CButton
          className="backBtn"
          onClick={(event) => {
            this._goAuth(event);
          }}
        />
      </div>
    );
  }
}

customElements.define('c-reg-page', CRegPage);

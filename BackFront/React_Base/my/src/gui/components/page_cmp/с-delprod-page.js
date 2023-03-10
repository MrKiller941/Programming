import React, { Component } from 'react';
import template from './template.js';
import './../../simple_cmp/c-button/c-button.js';
import './../../simple_cmp/c-label/c-label.js';
import { RouterFactory } from './../../../componentRouter/componentRouter.js';
import IOrouter from './../../../IOrouter/IOrouter.js';

class ctDelPage extends Component {
  constructor(props) {
    super(props);
    this.state = {};
    this._listenerDel = this._listenerDel.bind(this);
    this._listenerBack = this._listenerBack.bind(this);
  }

  componentDidMount() {
    this._render();
  }

  componentWillUnmount() {}

  _listenerDel(event) {
    event.stopPropagation();
    let panel = this.shadowRoot.querySelector('.panel');
    let name = panel.querySelector('.nm').querySelector('.name').getValue();

    IOrouter.delProduct(name)
      .then(() => {
        panel.querySelector('.message').innerHTML = '<br> Продукт успешно удален.';
      })
      .catch((err) => {
        panel.querySelector('.message').innerHTML = '<br> Ошибка удаленния.';
        console.log('Error to deleting product: ' + err);
      });
  }

  _listenerBack(event) {
    event.stopPropagation();
    let router = RouterFactory.createInstance();
    router.go('c-catalog-page');
  }

  _render() {
    if (!this.ownerDocument.defaultView) return;

    this.shadowRoot.innerHTML = template(this);

    this.shadowRoot
      .querySelector('.panel')
      .querySelector('.bt')
      .addEventListener('click', this._listenerDel);

    this.shadowRoot
      .querySelector('.panel')
      .querySelector('.btBack')
      .addEventListener('click', this._listenerBack);
  }

  render() {
    return <div className="ctDelPage"></div>;
  }
}

export default ctDelPage;

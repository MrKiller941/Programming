import React from 'react';
import ReactDOM from 'react-dom';

import template from './css-styles/button-template.js';

class CButton extends React.Component {
  constructor(props) {
    super(props);
    this.ref = React.createRef();
    this.state = {
      cValue: "",
    };
  }

  componentDidMount() {
    this._render();
  }

  componentDidUpdate(prevProps, prevState) {
    if (this.state.cValue !== prevState.cValue) {
      this._render();
    }
  }

  _render() {
    const shadowRoot = this.ref.current.attachShadow({ mode: "open" });
    shadowRoot.innerHTML = template(this.state.cValue);
  }

  attributeChangedCallback(attr, prev, next) {
    if (prev !== next) {
      if (attr === "value") {
        this.setState({
          cValue: next,
        });
      }
    }
  }

  render() {
    return (
      <div ref={this.ref}>
        <style>{this.props.style}</style>
        <div className="container">
          <button className="button">{this.state.cValue}</button>
        </div>
      </div>
    );
  }
}

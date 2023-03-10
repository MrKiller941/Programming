import React from 'react';

class CTextBar extends React.Component {
  constructor(props) {
    super(props);
    this.state = { cValue: '' };
  }

  componentDidMount() {
    this._render();
  }

  componentWillUnmount() {}

  static get observedAttributes() {
    return ['value'];
  }

  attributeChangedCallback(attr, prev, next) {
    if (prev !== next) {
      if (attr === 'value') {
        this.setState({ cValue: next });
      }
    }
    this._render();
  }

  getValue() {
    return this.shadowRoot.querySelector('.textbar').value;
  }

  _render() {
    if (!this.ownerDocument.defaultView) return;
    this.setState(this.state);
  }

  render() {
    return (
      <div className="c-textbar">
        {/* template function call */}
        {template(this)}
      </div>
    );
  }
}

customElements.define('c-textbar', CTextBar);

import React, { useState, useEffect } from 'react';

function CLabel(props) {
  const [cValue, setCValue] = useState("");

  useEffect(() => {
    _render();
  });

  const _render = () => {
    const template = `
      <div>
        ${cValue}
      </div>
    `;
    return template;
  }

  const handleValueChange = (event) => {
    setCValue(event.target.value);
  }

  return (
    <div onChange={handleValueChange}>
      { _render() }
    </div>
  );
}

export default CLabel;

import React from 'react';
import СButton from './simple_cmp/c-button.js';

function template() {
  function handleClick() {
    console.log('Button clicked!');
  }

  return (
    <div>
      <h1>My App</h1>
      <Button cValue="Click me" onClick={handleClick} />
    </div>
  );
}

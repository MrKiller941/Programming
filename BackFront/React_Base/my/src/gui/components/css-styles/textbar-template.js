import React from "react";

const style = { position: "relative" };

function TextInput({ value }) {
  return (
    <>
      <style>
        {`
        input[type="text"] {
          border-radius: 3px;
          background-color: rgba(0, 0, 0, 0.1);
          border: none;
          border-bottom: 2px solid #585858;
          outline: none;
        }
      `}
      </style>

      <input type="text" className="textbar" style={style} value={value} />
    </>
  );
}

export default TextInput;

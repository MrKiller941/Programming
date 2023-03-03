let _style = "position:relative;";


export default function(func) {return ` 
	<style>
		input[type="text"] {
  			border-radius: 3px;
  			background-color:rgba(0,0,0,0.1);
  			border: none;
    		border-bottom: 2px solid #585858;
    		outline: none;
		}
	</style> 
	
	
 	<input type="text" class="textbar" style=${_style} value=${func._cValue}></input>
`}
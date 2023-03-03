import template from './template.js'

import './../../simple_cmp/c-button/c-button.js'
import './../../simple_cmp/c-label/c-label.js'



class ctElement extends HTMLElement {
    
 	constructor() { 
   		super();
   		this._prod_id = "";
   		this._name 	  = "";
   		this._src 	  = "";
   		this._desc 	  = "";
   		this._cost 	  = "";
   		this.attachShadow({ mode: 'open' });            
 	}

 	connectedCallback() { 
  	 	this._render();   
	}

 	disconnectedCallback() { 
	     
 	} 

 	static get observedAttributes() {
   		return ["prod_id", "name", "src", "desc", "cost"]; 
	}                    

 	attributeChangedCallback(attr, prev, next) {
		if(prev !== next) {
     		if (attr==='name') {       
       			this._name = next;
     		}else
     	
     		if (attr==='src') {       
       			this._src = next;
     		}else
     	
     	 	if (attr==='desc') {       
       			this._desc = next;
     		}else
     	
     	 	if (attr==='cost') {       
       			this._cost = next;
     		}else
     	
     	 	if (attr==='prod_id') {       
       			this._prod_id = next;
     		}   
   		}
   	this._render()   
 	}
 
 
 	getButton(){
		return this.shadowRoot.querySelector(".container").querySelector(".buyBt");
	}
 //**********************************
 
 	_listener(event) {   
	
 	}   
    
 	_render() {  
   		if(!this.ownerDocument.defaultView) return;    
   		this.shadowRoot.innerHTML = template(this);  
 	}
 
 
}

customElements.define('c-cat-element', ctElement);
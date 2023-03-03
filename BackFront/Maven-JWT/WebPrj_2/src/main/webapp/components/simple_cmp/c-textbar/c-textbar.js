import template from './template.js'

class CTextBar extends HTMLElement {
    
 constructor() { 
   super();   
   this.attachShadow({ mode: 'open' }); 
   this._cValue = "";
 }

 connectedCallback() {  
   this._render();   
 }

 disconnectedCallback() {     
	 
 } 

 static get observedAttributes() {
   return ['value']; 
}                    

 attributeChangedCallback(attr, prev, next) {
	if(prev !== next) {
     	if (attr==='value') {       
       		this._cValue = next;
     	} 
   	}
   this._render();
 }

 //**********************************

	getValue(){
		return this.shadowRoot.querySelector(".textbar").value;
	}
	
	
 _render() {
   if(!this.ownerDocument.defaultView) return;    
   this.shadowRoot.innerHTML = template(this);         
 }
}

customElements.define('c-textbar',CTextBar);
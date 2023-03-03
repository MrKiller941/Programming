import template from './template.js'

class CLabel extends HTMLElement {
    
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

 _render() {
	 
   if(!this.ownerDocument.defaultView) return;
   this.shadowRoot.innerHTML = template(this);             
 }
}

customElements.define('c-label',CLabel);
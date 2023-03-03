import template from './template.js'

import './../../simple_cmp/c-button/c-button.js'
import './../../simple_cmp/c-label/c-label.js'
import './../../simple_cmp/c-textbar/c-textbar.js'



class cRegistration extends HTMLElement {
    
 constructor() { 
   super();  
   this.attachShadow({ mode: 'open' });            
 }

 connectedCallback() {   
   this._render();   
 }

 disconnectedCallback() {      
 } 

 static get observedAttributes() {
   return []; 
}                    

 attributeChangedCallback(attr, prev, next) {
	
   this._render()   
 }
 
 
 	getLogin(){
	
		return this.shadowRoot.querySelector(".regstr").querySelector(".login_bar").getValue();
	}
	
 	getPassword(){
	
		return this.shadowRoot.querySelector(".regstr").querySelector(".password_bar").getValue();
	}
	
	
  //**********************************
 	   
 	_render() {  
   		if(!this.ownerDocument.defaultView) return;    
   		this.shadowRoot.innerHTML = template(this);
 	}
 
 
}

customElements.define('c-reg-panel',cRegistration);
import template from './template.js'

import './../../complex_cmp/c-reg-panel/c-reg-panel.js'
import './../../complex_cmp/c-log-panel/c-log-panel.js'
import './../../simple_cmp/c-button/c-button.js'

	
import {UserFactory} 	from 	'./../../../classes/user.js'
import {RouterFactory} 	from 	'./../../../componentRouter/componentRouter.js'
import IOrouter 		from 	'./../../../IOrouter/IOrouter.js'

class cPReg extends HTMLElement {
    
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
 
 //**********************************
 
 	_reg(event) {                 
   		event.stopPropagation();
   		let user = UserFactory.createInstance();
   		
   		user.setLogin	(this.shadowRoot.querySelector(".rpage").querySelector(".rpanel").getLogin());
   		user.setPassword(this.shadowRoot.querySelector(".rpage").querySelector(".rpanel").getPassword());
   		let router = RouterFactory.createInstance(); 
   		IOrouter.signUp(user.getLogin(), user.getPassword()).then((res)=>{
			router.go("c-log-page");
		}).catch((err)=>{
			console.log("Error registration: " + err);
			router.go("c-reg-page");
		});
 	}   
   
    
    _goAuth(event) {                 
   		event.stopPropagation();
   		let router = RouterFactory.createInstance(); 
   		router.go("c-log-page");
 	}   
    
    
 	_render() {  
   		if(!this.ownerDocument.defaultView) return;    
  		this.shadowRoot.innerHTML = template(this); 
  		this.shadowRoot.querySelector(".rpage").querySelector(".sendBtn").addEventListener('click', this._reg.bind(this));
  		this.shadowRoot.querySelector(".rpage").querySelector(".backBtn").addEventListener('click', this._goAuth.bind(this));
 	}
 
 
}

customElements.define('c-reg-page',cPReg);
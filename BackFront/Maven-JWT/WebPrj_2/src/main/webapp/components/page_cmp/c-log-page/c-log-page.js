import template from './template.js'

import './../../complex_cmp/c-log-panel/c-log-panel.js'
import './../../simple_cmp/c-button/c-button.js'

	
import {UserFactory} 	from 	'./../../../classes/user.js'
import {RouterFactory} 	from 	'./../../../componentRouter/componentRouter.js'
import IOrouter 		from 	'./../../../IOrouter/IOrouter.js'


class cPLogin extends HTMLElement {
    
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
   		this._render();   
 	}
 
 //**********************************
 
 	_auth(event) {                 
   		event.stopPropagation();
   		let user = UserFactory.createInstance();
   		
   		user.setLogin(this.shadowRoot.querySelector(".lpage").querySelector(".logPanel").getLogin());
   		user.setPassword(this.shadowRoot.querySelector(".lpage").querySelector(".logPanel").getPassword());
   		let router = RouterFactory.createInstance(); 
   		
   		IOrouter.signIn(user.getLogin(), user.getPassword()).then((res)=>{
			user.setPassword(res);
			router.go("c-catalog-page");
			
		}).catch((err)=>{
			console.log("Error authorisation: " + err);
			router.go("c-log-page");
		});
 	}   
   
    
    _goReg(event) {                 
   		event.stopPropagation();
   		let router = RouterFactory.createInstance(); 
   		router.go("c-reg-page");
 	}   
    
    
 	_render() {  
   		if(!this.ownerDocument.defaultView) return;    
  		this.shadowRoot.innerHTML = template(this); 
  		this.shadowRoot.querySelector(".lpage").querySelector(".logButton").addEventListener('click', this._auth.bind(this));  
  		this.shadowRoot.querySelector(".lpage").querySelector(".regButton").addEventListener('click', this._goReg.bind(this));
 	}
 
 
}

customElements.define('c-log-page',cPLogin);
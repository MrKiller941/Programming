import template from './template.js'

import './../../complex_cmp/c-ctg-element/c-ctg-element.js'
import './../../complex_cmp/c-basket-panel/c-basket-panel.js'

import {RouterFactory} 		from 	'./../../../componentRouter/componentRouter.js'
import {UserFactory}		from 	'./../../../classes/user.js'
import IOrouter 			from 	'./../../../IOrouter/IOrouter.js'



class cCatalog extends HTMLElement {
    
 	constructor() { 
   		super();
   		this._busket = undefined;
   		this._elements = new Array();
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
 
 	_listener(event) {   
	
 	}   
    
    _listenerAddButton(event) {   
		event.stopPropagation();
		let router = RouterFactory.createInstance(); 
   		router.go("c-addprod-page");
 	}   
    
    _listenerDelButton(event) {   
		event.stopPropagation();
		let router = RouterFactory.createInstance(); 
   		router.go("c-delprod-page");
 	}   
    
    
    
 	_render() {  
   		if(!this.ownerDocument.defaultView) return;
   		this.shadowRoot.innerHTML = template(this); 
   		let user = UserFactory.createInstance();
   		
   		
   		this._busket = this.shadowRoot.querySelector(".busket");
   		this.shadowRoot.querySelector(".addProd").addEventListener("click", this._listenerAddButton.bind(this));
   		this.shadowRoot.querySelector(".delProd").addEventListener("click", this._listenerDelButton.bind(this));
   		
   		
    	IOrouter.getCatalog(user.getLogin(), user.getPassword()).then((res)=>{
			this._elements = res;
   			for(let i = 0; i < this._elements.length; i++){
				let elem = document.createElement('c-cat-element');
				elem.setAttribute("prod_id", this._elements[i].id);
				elem.setAttribute("name", 	 this._elements[i].medic_names);
				elem.setAttribute("desc", 	 this._elements[i].medic_count);
				elem.setAttribute("cost", 	 this._elements[i].medic_cost);
				elem.setAttribute("src",  	 this._elements[i].img);
				
				
				
				function eventFunc(event) {                 
   					event.stopPropagation();
   					this._busket.addAttributeAtBusket(i, this._elements[i].id, this._elements[i].medic_names,
   								 this._elements[i].img, this._elements[i].medic_cost);
 				}  
				
				
 				
				
				this.shadowRoot.querySelector(".catalog").appendChild(elem);
				elem.getButton().addEventListener('click', eventFunc.bind(this));  
				
			}
			
		}).catch((err)=>{
			console.log("Error to geticng catalog: " + err);
		});
		
 	}
 
 
}

customElements.define('c-catalog-page',cCatalog);
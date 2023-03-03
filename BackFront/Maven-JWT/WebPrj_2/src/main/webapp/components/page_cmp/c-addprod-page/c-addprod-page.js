import template from './template.js'

import './../../simple_cmp/c-button/c-button.js'
import './../../simple_cmp/c-label/c-label.js'
import {RouterFactory} 	from 	'./../../../componentRouter/componentRouter.js'
import IOrouter 		from 	'./../../../IOrouter/IOrouter.js'


class ctAddPage extends HTMLElement {
    
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
 	
 	_listenerAdd(event){
		event.stopPropagation();
		let panel = this.shadowRoot.querySelector(".panel");
		let name  = panel.querySelector(".nm").querySelector(".name").getValue();
		let cost  = panel.querySelector(".cs").querySelector(".cost").getValue();
		let img   = panel.querySelector(".im").querySelector(".img").getValue();
		let count = panel.querySelector(".ct").querySelector(".count").getValue();
		
		IOrouter.postNewProduct(name, cost, count, img).then(()=>{
			panel.querySelector(".message").innerHTML = "<br> Продукт успешно добавлен в каталог."
		}).catch((err)=>{
			panel.querySelector(".message").innerHTML = "<br> Ошибка добавления в каталог."
			console.log("Error to adding new product: " + err);
		});
		
	} 
    
    
    _listenerBack(event){
		event.stopPropagation();
		let router = RouterFactory.createInstance(); 
   		router.go("c-catalog-page");
	} 
	
    
 	_render() {  
   		if(!this.ownerDocument.defaultView) return;
   		
   		this.shadowRoot.innerHTML = template(this); 
   		
   		this.shadowRoot.querySelector(".panel").querySelector(".bt")
   					   .addEventListener('click', this._listenerAdd.bind(this));
   					   
   		this.shadowRoot.querySelector(".panel").querySelector(".btBack")
   					   .addEventListener('click', this._listenerBack.bind(this));
   		
 	}
 
 
}

customElements.define('c-addprod-page', ctAddPage);
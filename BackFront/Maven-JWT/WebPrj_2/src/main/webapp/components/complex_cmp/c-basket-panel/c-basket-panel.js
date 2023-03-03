import template from './template.js'

import './../../simple_cmp/c-button/c-button.js'
import './../../simple_cmp/c-label/c-label.js'
import {busketProduct} from './../../../classes/busketProduct.js'


class ctBusket extends HTMLElement {
    
 	constructor() { 
   		super();
   		this.productlist = new Array();
   		
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
 	
 	
 	addAttributeAtBusket(index, prod_id, prod_name, img_src, cost){ // обновление товаров в корзине.
		this.productlist.push(new busketProduct(index, prod_id, prod_name, img_src, cost));
		
		
		let line = this.shadowRoot.querySelector(".dropdownContainer").querySelector(".dropdownContent")
			.querySelector(".dropdownContentLineMessage");
			
		line.innerHTML = "";
		for(let i = 0; i < this.productlist.length; i++){
			line.innerHTML += this.productlist[i].prod_name + "   " + this.productlist[i].cost + " руб <br><br>";
		}
	} 
	
	
	
 //**********************************
 
 	_listener(event) {   
	
 	}   
    
 	_render() {  
   		if(!this.ownerDocument.defaultView) return;    
   		this.shadowRoot.innerHTML = template(this);  
 	}
 
 
}

customElements.define('c-basket-panel', ctBusket);
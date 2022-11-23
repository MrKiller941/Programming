import {createButton, createForm, createTextbar, createDiv, createImg, createMessage} from "../view/domConstructor.js"
import {ProcessAutorizationForm ,ProcessRegistrationForm} from "../model/formProcessor.js"

export const medicineList = (function() {
//*********************************************  

let root = undefined;
let catalog_data = undefined
let messCont = createDiv("contentMessage", null, "");

const style_back =
"background: rgba(50, 50, 50, 0.25);"+
"color: rgb(220, 220, 220 )!important;"+
"border-radius: 20px;"+
"margin-left: auto;"+
"margin-right: 75%;"+
"width: 600px;";


const style_paragraph =
"background: rgba(50, 50, 50, 0.75);"+	
"border-radius: 6px;"+
"margin-left: auto;"+
"margin-right: auto;"+
"width: 50%;"+
"height: 23%;";

const style_img =
"border-radius: 2px;"+
"border-color: rgb(20, 20, 20);"+
"border-width: 2px;";


function _render(){
	createMessage("");

	//===========================================
	let del_elements = root.getElementsByTagName("form");
	for(var i = 0; i < del_elements.length; i++)
		del_elements[i].remove();


	const catalog_form = createForm("catalog_form", style_back);
		
	
	
	//===============
	for(i = 0; i < catalog_data.length; i++){
		let pr_c = document.createElement("div");
		pr_c.setAttribute("align", "center");
		pr_c.setAttribute("style", style_paragraph);
		
		_createCatalogElement(catalog_data[i], pr_c);
		
		catalog_form.appendChild(pr_c);
		catalog_form.appendChild(document.createElement("br"));
		catalog_form.appendChild(document.createElement("br"));
		catalog_form.appendChild(document.createElement("br"));
		catalog_form.appendChild(document.createElement("br"));
	}
	
	
	
	//===============
	
	root.appendChild(catalog_form);
	//=========================================================================
}


function _createCatalogElement(element, paragraph){
	paragraph.setAttribute("id", "styleCatalogElement");
		
	let image = createImg("styleCatalogImg", element.img, "200", "130");
	image.setAttribute("style", style_img);
	console.log(element.img)
	let name = createDiv("styleCatalogName", null, "");
	name.innerHTML = element.medic_names;
	
	let cost = createDiv("styleCatalogCost", null, "");
	cost.innerHTML = element.medic_cost + " р";
	
	let count = createDiv("styleCatalogCount", null, "");
	count.innerHTML = element.medic_count + " Штук";

	paragraph.appendChild(name);
	paragraph.appendChild(cost);
	paragraph.appendChild(image);
	paragraph.appendChild(count);
}


function _init(_root, _catalog_data) {
   root = _root;
   catalog_data = _catalog_data; 
   _render();
}


return {
  renderCatalog: _init  
 };

//*********************************************   
})();
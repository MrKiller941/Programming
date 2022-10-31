var medicineList = (function() {
//*********************************************  

var root = undefined;
var catalog_data = undefined
var messCont = createDiv("contentMessage", null, "");

var style_back =
"background: rgba(50, 50, 50, 0.25);"+
"color: rgb(220, 220, 220 )!important;"+
"border-radius: 20px;"+
"margin-left: auto;"+
"margin-right: 75%;"+
"width: 600px;";


var style_paragraph =
"background: rgba(50, 50, 50, 0.75);"+	
"border-radius: 6px;"+
"margin-left: auto;"+
"margin-right: auto;"+
"width: 50%;"+
"height: 23%;";

var style_img =
"border-radius: 2px;"+
"border-color: rgb(20, 20, 20);"+
"border-width: 2px;";


function _render(){
	createMessage("");

	//===========================================
	var del_elements = root.getElementsByTagName("form");
	for(var i = 0; i < del_elements.length; i++)
		del_elements[i].remove();


	var catalog_form = createForm("catalog_form", style_back);
		
	
	
	//===============
	for(i = 0; i < catalog_data.length; i++){
		var pr_c = document.createElement("div");
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
		
	var image = createImg("styleCatalogImg", element.img, "200", "130");
	image.setAttribute("style", style_img);
	console.log(element.img)
	var name = createDiv("styleCatalogName", null, "");
	name.innerHTML = element.medic_names;
	
	var cost = createDiv("styleCatalogCost", null, "");
	cost.innerHTML = element.medic_cost + " р";
	
	var count = createDiv("styleCatalogCount", null, "");
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
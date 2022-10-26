
function createCatalog(catalog_name, catalog_data){
	createMessage("");
	console.log(catalog_data);
	var del_elements = document.getElementsByTagName("form");
	for(var i = 0; i < del_elements.length; i++)
		del_elements[i].remove();

	var catalog_form = document.createElement("form");
	catalog_form.setAttribute("id", catalog_name);
	
	
	for(i = 0; i < catalog_data.length; i++){
		var pr_c = document.createElement("div");
		
		createCatalogElement(catalog_data[i], pr_c);
		
		catalog_form.appendChild(pr_c);
		catalog_form.appendChild(document.createElement("br"));
		catalog_form.appendChild(document.createElement("br"));
	}
	var addForm_button = document.createElement("input");
	addForm_button.setAttribute("type", "button");
	addForm_button.setAttribute("id", "buttonContainer");
	addForm_button.setAttribute("value", "Добавить");
	catalog_form.appendChild(addForm_button)
	document.body.appendChild(catalog_form);
}

function createCatalogElement(element, paragraph){
	var button_style = "position: relative;"
	+"left: 17.7vw;"
	+"width: 8vw;"
	+"height: 3vw;"
	+"";
	
	paragraph.setAttribute("id", "styleCatalogElement");
	paragraph.setAttribute("align", "center");	
	var image = document.createElement("img");
	image.setAttribute("id", "styleCatalogImg");
	image.setAttribute("src", element.img)
	image.setAttribute("width", "400");
	image.setAttribute("height", "450");
	
	
	var name = document.createElement("div");
	name.setAttribute("id", "styleCatalogName");
	name.innerHTML = element.medic_names;
	
	var cost = document.createElement("div");
	cost.setAttribute("id", "styleCatalogCost");
	cost.innerHTML = element.medic_cost + " рублей."; 
	
	
	var count = document.createElement("div");
	count.setAttribute("id", "styleCatalogCost");
	count.innerHTML = element.medic_count + " штук."
	
	
	paragraph.appendChild(name);
	paragraph.appendChild(cost);
	paragraph.appendChild(image);
	paragraph.appendChild(count)
	
}

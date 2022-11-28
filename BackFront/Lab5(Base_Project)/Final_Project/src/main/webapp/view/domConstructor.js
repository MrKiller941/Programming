export function createButton(id, style, value, onClick, classType){
	let button = document.createElement("input");
	button.setAttribute("type", "button");
	button.setAttribute("id", id);
	button.setAttribute("style", style);
	button.setAttribute("value", value);
	button.setAttribute("onClick", onClick);
	button.setAttribute("class", classType);
	return button;
}


export function createForm(id, style){
	let form = document.createElement("form");
	form.setAttribute("id", id);
	form.setAttribute("style", style);
	return form;
}


export function createTextbar(id, style, value){
	let bar = document.createElement("input");
	bar.setAttribute("type", "text");
	bar.setAttribute("id", id);
	bar.setAttribute("style", style);
	bar.setAttribute("value", value);
	return bar;
}


export function createDiv(id, style, value){
	let div = document.createElement("div");
	div.setAttribute("id", id);
	div.setAttribute("style", style);
	div.setAttribute("value", value);
	return div;
}

export function createImg(id, src, width, height){
	let image = document.createElement("img");
	image.setAttribute("id", id);
	image.setAttribute("src", src);
	image.setAttribute("width", width);
	image.setAttribute("height", height);
	return image;
}


export function createMessage(out_mess){
	document.getElementById("massageField").remove();
	let mess = document.createElement("div");
	mess.setAttribute("id", "massageField");
	mess.setAttribute("align", "center");
	mess.innerHTML = out_mess;
	document.body.appendChild(mess);
}

function createData(){ // новая запись лекарства
var del_elements = document.getElementsByTagName("form");
	for(var i = 0; i < del_elements.length; i++)
del_elements[i].remove(); // удаляет все элементы формы
var add_form = document.createElement("form"); // создание контейнера для всех элементов
	add_form.setAttribute("id", "Data");
	
var pr = document.createElement("p"); // создание элемента с тэгеом параграф
pr.setAttribute("align", "center");

var inp_name = document.createElement("input"); // создание переменной с тэгом input
var inp_cost = document.createElement("input");
var inp_count = document.createElement("input");
var inp_img = document.createElement("input");

inp_name.setAttribute("type", "text"); // задаём атрибуты для тэга type
inp_cost.setAttribute("type", "text");
inp_count.setAttribute("type", "text");
inp_img.setAttribute("type", "text");




var add_button = document.createElement("input");
	add_button.setAttribute("type", "button");
	add_button.setAttribute("id", "buttonContainer");
	add_button.setAttribute("value", "Добавить");
	
var back_button = document.createElement("input");
	back_button.setAttribute("type", "button");
	back_button.setAttribute("id", "buttonContainer");
	back_button.setAttribute("value", "Назад");

add_form.appendChild(inp_name); // добавление элемента на форму
add_form.appendChild(inp_cost);
add_form.appendChild(inp_count);
add_form.appendChild(inp_img);
add_form.appendChild(add_button);
add_form.appendChild(back_button);
document.body.appendChild(add_form);
add_button.setAttribute("onClick", "authorizationProcess(true)");
}
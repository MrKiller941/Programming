import {createButton, createForm, createTextbar, createDiv, createImg, createMessage} from "../view/domConstructor.js"
import {ProcessAutorizationForm, ProcessRegistrationForm} from "../model/formProcessor.js"
import {ProcessAutorization, ProcessRegistration} from "../model/Processor.js"

export const registrationForm = (function() {
//*********************************************  

let root = undefined;


function _render() {
	const buttonIn = 
	"position: relative;"
	+"top: 20px;";

	
	const buttonBack =
	"position: relative;"
  	+"top: 20px;";
  	
	createMessage("");
	let del_forms = root.getElementsByTagName("form");
	let del_len = del_forms.length;
	for(let i = del_len-1; i > -1; i--){
		del_forms[i].remove();
	}
	
	let reg_form = createForm("signUp_form", null);
	let pr = document.createElement("p");
	pr.setAttribute("align", "center");
	
	pr.innerHTML += "Регистрация<br>";
	
	let inp_log = createTextbar("reg_login_bar", null, "");
	let inp_pass = createTextbar("reg_password_bar", null, "");
	
	pr.innerHTML += "Логин:";
	pr.appendChild(document.createElement("br"));  
	pr.appendChild(inp_log);
	pr.appendChild(document.createElement("br"));  
	pr.innerHTML += "Пароль:";
	pr.appendChild(document.createElement("br"));  
	pr.appendChild(inp_pass);
	
	const button_container = document.createElement("div");
	const reg_button = createButton("buttonContainer", buttonIn, "Продолжить", null, undefined);
	const back_button = createButton("buttonContainer", buttonBack, "Назад", null, undefined);
	reg_button.addEventListener("click", ProcessRegistration);
	back_button.addEventListener("click", ProcessAutorizationForm);
	
	button_container.appendChild(reg_button);
	button_container.appendChild(back_button);
	pr.appendChild(button_container);
	reg_form.appendChild(pr); 
	root.appendChild(reg_form);
}    


function _init(_root) {
   root = _root; 
   _render();
}


return {
  renderSignUp: _init  
 };

//*********************************************   
})();
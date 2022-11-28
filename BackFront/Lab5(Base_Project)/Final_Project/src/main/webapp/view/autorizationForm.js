import {createButton, createForm, createTextbar, createDiv, createImg, createMessage} from "../view/domConstructor.js"
import {ProcessAutorizationForm, ProcessRegistrationForm} from "../model/formProcessor.js"
import {ProcessAutorization, ProcessRegistration} from "../model/Processor.js"

export const autorizationForm = (function() {
//*********************************************  

let root = undefined;


function _render() {
	const buttonIn = 
	"position: relative;"
	+"top: 20px;";
	
	const buttonUp =
	"position: relative;"
 	+"top: 20px;"
	
	let del_forms = root.getElementsByTagName("form");
	let del_len = del_forms.length;
	for(let i = del_len-1; i > -1; i--){
		del_forms[i].remove();
	}

	let reg_form = createForm("signIn_form", null);
	let pr = document.createElement("p");
	pr.setAttribute("align", "center");
	
	let inp_log = createTextbar("login_bar", null, "");
	let inp_pass =  createTextbar("password_bar", null, "");
	
	pr.innerHTML += "Логин: <br>";
	pr.appendChild(inp_log);
	pr.appendChild(document.createElement("br"));  
	pr.innerHTML += "Пароль:";
	pr.appendChild(document.createElement("br"));  
	pr.appendChild(inp_pass);
	
	let button_container_in = document.createElement("div");
	let signIn_button = createButton("buttonContainer", buttonIn, "Авторизация", undefined, undefined);
	let signUp_button = createButton("buttonContainer", buttonUp, "Регистрация", undefined, undefined);
	signIn_button.addEventListener("click", ProcessAutorization);
	signUp_button.addEventListener("click", ProcessRegistrationForm);  
	
	button_container_in.appendChild(signIn_button);
	button_container_in.appendChild(signUp_button);
	pr.appendChild(button_container_in);
	reg_form.appendChild(pr);
	root.appendChild(reg_form);
	document.body.appendChild(root);
}    


function _init(_root) {
   root = _root; 
   _render();
}


return {
  renderSignIn: _init  
 };

//*********************************************   
})();
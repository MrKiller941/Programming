import * as form from "../model/formProcessor.js"
import * as transfer from "../data_transfer/Transferclass.js"
import * as constructor from "../view/domConstructor.js"

let current_user_login = undefined;
let current_user_password = undefined;
let current_calatog = undefined;


export function ProcessAutorization(){
	let login = document.getElementById("login_bar").value;
	let password = document.getElementById("password_bar").value;
	
	transfer.Transferclass.checkSignIn(login, password).then(()=>{
		current_user_login = login;
		current_user_password = password;
		transfer.Transferclass.getCatalog().then((resolve)=>{
			form.ProcessMedicineList(resolve);
		}).catch((error)=>{
			constructor.createMessage("error: "+ error + "<br>");
		});
		
	}).catch((error)=>{
		constructor.createMessage(error + "   Неправильный логин или пароль.<br>");
	});
	
}


export function ProcessRegistration(){
	let login = document.getElementById("reg_login_bar").value;
	let password = document.getElementById("reg_password_bar").value;
	
	transfer.Transferclass.trunSignUp(login, password).then(()=>{
		form.ProcessAutorizationForm();
	}).catch((error)=>{
		constructor.createMessage(error + " Неверные данные для регистрации.<br>");
	});
	
}
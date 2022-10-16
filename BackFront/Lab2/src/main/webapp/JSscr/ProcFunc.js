function registrationProcess(state){
	if(state == true){
		createSignInForm(signIn_form);
		createMessage("Вы успешно зарегистрировались!<br>");
	}else{
		createMessage("Регистрация неудачна, попробуйте еще раз!<br>");
	}
}


function authorizationProcess(state){
	if(state == true){
		var catalog_date = new Array();
		catalog_date = getCatalog();
		createCatalog(catalog_form, catalog_date);
		
	}else{
		createMessage("Неправильный логин или пароль!<br>");
	}
}
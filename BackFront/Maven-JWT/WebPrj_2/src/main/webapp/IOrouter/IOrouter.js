export default function IOrouter(){
//*********************************************  
	this.flagAsync = false;
}


IOrouter.signIn =  async (login, password) =>{ // функция лежит в основе переменной let
	let response = await fetch("api/auth", {
		method: "POST",
		headers: {'Content-Type': 'application/json;charset=utf-8'},
		body:  JSON.stringify([login, password]),
	});
    
    if(response.ok){
		return true;
	}
	else{
		throw response.status;
	}
}



IOrouter.signUp = async (login, password) => {
	let response = await fetch("api/reg", {
		method: "POST",
		headers: {'Content-Type': 'application/json;charset=utf-8'},
		body:  JSON.stringify([login, password]),
	});
    
    if(response.ok){
		return true;
	}
	else{
		throw response.status;
	}
}


IOrouter.getCatalog = async ()=>{
	let catalogJSON = new Array();
	let response = await fetch("api/catalogs/medic-catalog", {
		method: "GET",
	});
    
    if(response.ok){
		catalogJSON = await response.json();
		return catalogJSON;
	}
	else{
		throw response.status;
	}
}


IOrouter.postNewProduct = async (name, cost, count, img) =>{
	
	let response = await fetch("api/catalogs/medic-catalog/add", {
		method: "POST",
		headers: {'Content-Type': 'application/json;charset=utf-8'},
		body:  JSON.stringify([name, cost, count, img]),
	});
    
    if(response.ok){
    	
    	return true;
    }else
    	throw response.status;
}



IOrouter.delProduct = async function(name){
    let response = await fetch("api/catalogs/medic-catalog/del", {
  	method: 'DELETE',
  	headers: {
    'name': JSON.stringify([name])
  	},
	});
    
    if(response.ok){
    	
    	return true;
    }else
    	throw response.status;
}
//*********************************************   

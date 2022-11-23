package interfaces;

import jakarta.enterprise.context.ApplicationScoped;
import jakarta.json.bind.Jsonb;
import jakarta.json.bind.JsonbBuilder;

import java.util.ArrayList;
import java.util.List;

import Entity.Med_Product;
import Entity.ClassFactory;
import controllers.IDBController;
import interfaces.IModel;

@ApplicationScoped
public class Model implements IModel{
	
	private IDBController IDBController = null;
	
	
	@Override
	public boolean checkUserData(String data) {
		this.injectIDBController(ClassFactory.injectDBController());
		
		Jsonb jsonb = JsonbBuilder.create();          
	 	List<String> logs;
      	try { 
    	  	logs = jsonb.fromJson(data, List.class);  
    	  	
    	  	if(IDBController.DataIsCorrect(logs.get(0), logs.get(1))) {
    	  		return true;
    	  	}else {
    	  		return false;
    	  	}
      	}
      	catch (Exception e) {
      		System.out.println("ERROR TO CHECK DATA FROM DB: " + e.getMessage());
      		return false;
      	}
	}
	
	
	@Override
	public boolean registrateNewUser(String data) {
		this.injectIDBController(ClassFactory.injectDBController());
		
		Jsonb jsonb = JsonbBuilder.create();          
	 	List<String> logs;
      	try { 
    	  	logs = jsonb.fromJson(data, List.class);         
    	  	
    	  	if(IDBController.RegistrationNewUser(logs.get(0), logs.get(1))) {
    	  		return true;
    	  	}else
    	  	{
    	  		return false;
    	  	}
    	  	
      	}
      	catch (Exception e) {
      		System.out.println("ERROR TO REGISTRATE NEW DATA INTO DB: " + e.getMessage());
      		return false;
      	}
	}
	
	@Override
	public String getGameKey(String id_key) {
		this.injectIDBController(ClassFactory.injectDBController());
		
		return IDBController.GetGameKey(id_key);
	}
	
	@Override
	public String getFullCatalog() {
		this.injectIDBController(ClassFactory.injectDBController());
		
		Jsonb jsonb = JsonbBuilder.create();          
	 	ArrayList<Med_Product> catalog;
	 	String resultJSON;
      	try { 
      		catalog = IDBController.GetGameCatalog();
      		resultJSON = jsonb.toJson(catalog);
      		return resultJSON;
      	}
      	catch (Exception e) {
      		System.out.println("GET CATALOG ERROR: " + e.getMessage());
      		return null;
      	}
	}	
	
	private void injectIDBController(IDBController controller) {
		if(this.IDBController == null)
			this.IDBController = controller;
	}
      	
}

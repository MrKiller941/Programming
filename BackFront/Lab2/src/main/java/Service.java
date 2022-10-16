
import jakarta.ws.rs.Path;

import jakarta.ws.rs.GET;
import jakarta.ws.rs.POST;

import jakarta.ws.rs.Produces;
import jakarta.ws.rs.Consumes;

import jakarta.ws.rs.core.Response;

import jakarta.json.bind.Jsonb;
import jakarta.json.bind.JsonbBuilder;
import jakarta.json.bind.JsonbException;

import java.lang.reflect.Type;
import java.util.ArrayList;
import java.util.List;



@Path("/")
public class Service {
	DataBaseController dataBase = new DataBaseController();
	
	@POST
 	@Path("/signIn")
 	@Consumes("application/json")
	@Produces("text/plain")
 	public String signIn(String fileJSON) throws Exception 
 	{            
	 	Jsonb jsonb = JsonbBuilder.create();          
	 	List<String> logs;
      	try { 
    	  	logs = jsonb.fromJson(fileJSON, List.class);  
    	  	
    	  	if(dataBase.DataIsCorrect(logs.get(0), logs.get(1))) {
    	  		return "1";
    	  	}else {
    	  		return "0";
    	  	}
      	}
      	catch (Exception e) {
      		return e.getMessage();
      	}

 	}
 
 
	@POST
 	@Path("/signUp")
 	@Consumes("application/json")
	@Produces("text/plain")
 	public String signUp(String fileJSON) throws Exception 
 	{            
	 	Jsonb jsonb = JsonbBuilder.create();          
	 	List<String> logs;
      	try { 
    	  	logs = jsonb.fromJson(fileJSON, List.class);         
    	  	
    	  	if(dataBase.RegistrationNewUser(logs.get(0), logs.get(1))) {
    	  		return "1";
    	  	}else
    	  	{
    	  		return "0";
    	  	}
      	}
      	catch (Exception e) {
      		return e.getMessage();
      	}
 	}
	
	@GET
 	@Path("catalog/getList")
	@Produces("application/json")
 	public Response push() throws Exception 
 	{            
	 	Jsonb jsonb = JsonbBuilder.create();          
	 	ArrayList<Names_Medic> catalog;
	 	String resultJSON;
      	try { 
      		catalog = dataBase.Medicines();
      		resultJSON = jsonb.toJson(catalog);
    	  		System.out.println(resultJSON);
      	}
      	catch (Exception e) {
      		System.out.println(e.getMessage());
      		return Response.status(Response.Status.BAD_REQUEST).entity(e.getMessage()).build();
      	}
      	return Response.ok(resultJSON).build();  
 	}
	
}
 
 
 




 //hash (pas log + sault)
 //или иметь постоянную проверку логина и пароля или проверять есть ли токен


import jakarta.ws.rs.Path;

import jakarta.ws.rs.GET;
import jakarta.ws.rs.POST;

import jakarta.ws.rs.Produces;
import jakarta.ws.rs.Consumes;

import jakarta.ws.rs.core.Response;
import jakarta.inject.Inject;
import interfaces.IModel;

@Path("/")
public class Service {
	@Inject
	private IModel model;
	
	@POST
 	@Path("/SignIn")
 	@Consumes("application/json")
	@Produces("text/plain")
 	public String signIn(String fileJSON) throws Exception 
 	{   
		System.out.println("================" + fileJSON + "======================================");
		boolean res = model.checkUserData(fileJSON);
		if(res) {
			return "200";
		}
		
		return "501";
		
 	}
	// отправка данных с браузера
	// путь к ресурсу
	// тип данных, которые придут от браузера
	// отправляемый тип данных
	@POST
 	@Path("/SignUp")
 	@Consumes("application/json")
	@Produces("text/plain")
 	public String signUp(String fileJSON) throws Exception 
 	{            
		System.out.println("================" + fileJSON + "======================================");
		boolean res = model.registrateNewUser(fileJSON);
		
		if(res) {
			return "200";
		}
		return "500";
		
 	}
	
	// получение данных из сервера
	@GET
 	@Path("Catalog/GameCatalog")
	@Produces("application/json")
 	public Response pushCatalog() throws Exception 
 	{            
	          
		 String resultJSON;
		 resultJSON = model.getFullCatalog();
		 	
		 
		 if(resultJSON != null)
		 	return Response.ok(resultJSON).build(); 
		 else {
		 	return Response.status(Response.Status.BAD_REQUEST).entity("501").build();
		 }
 	}
}

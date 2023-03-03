import jakarta.ws.rs.Path;

import jakarta.ws.rs.GET;
import jakarta.ws.rs.POST;

import jakarta.ws.rs.Produces;
import jakarta.ws.rs.container.ContainerRequestContext;
import jakarta.ws.rs.Consumes;
import jakarta.ws.rs.DELETE;
import jakarta.ws.rs.core.Context;
import jakarta.ws.rs.core.Response;

import java.util.List;

import builder.Build.Built;
import jakarta.inject.Inject;
import jakarta.json.bind.Jsonb;
import jakarta.json.bind.JsonbBuilder;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import modelLayer.IModel;

@Path("/")
public class Service {
	@Context
	ContainerRequestContext requestContext;
	
	@Inject @Built
	IModel model;
	
	@POST
 	@Path("/auth")
 	@Consumes("application/json")
	@Produces("text/plain")
 	public Response signIn(String fileJSON) throws Exception 
 	{   
		System.out.println("================" + fileJSON + "======================================");
		Jsonb jsonb = JsonbBuilder.create();          
	 	List<String> logs;
	 	logs = jsonb.fromJson(fileJSON, List.class);
		boolean res = model.checkUserData(logs.get(0), logs.get(1));
		
		if(res) {
			return Response.ok().build();
		}
		
		return Response.status(Response.Status.BAD_REQUEST).entity("501").build();
		
 	}
	
	// отправка данных с браузера
	// путь к ресурсу
	// тип данных, которые придут от браузера
	// отправляемый тип данных
	@POST
 	@Path("/reg")
 	@Consumes("application/json")
	@Produces("text/plain")
 	public Response signUp(String fileJSON) throws Exception 
 	{            
		System.out.println("================" + fileJSON + "======================================");
		
		Jsonb jsonb = JsonbBuilder.create();          
	 	List<String> logs;
	 	logs = jsonb.fromJson(fileJSON, List.class);
		boolean res = model.registrateNewUser(logs.get(0), logs.get(1));
		
		if(res) {
			return Response.ok().build();
		}
		return Response.status(Response.Status.BAD_REQUEST).entity("501").build();
		
 	}
	
	
	// получение данных из сервера.
	@GET
 	@Path("catalogs/medic-catalog")
	@Produces("application/json")
 	public Response pushCatalog() throws Exception 
 	{            
	          
		 String resultJSON;
		 Jsonb jsonb = JsonbBuilder.create();
		 
		 resultJSON =  jsonb.toJson(model.getFullCatalog());
		 	
		 
		 if(resultJSON != null)
		 	return Response.ok(resultJSON).build(); 
		 else {
		 	return Response.status(Response.Status.BAD_REQUEST).entity("501").build();
		 }
 	}
	
	
	@POST // отправляем данные на сервер.
	@Path("catalogs/medic-catalog/add")
	@Consumes("application/json")
	@Produces("text/plain")
	public Response addNewProd(String fileJSON) throws Exception 
 	{            
	          
		System.out.println("================" + fileJSON + "======================================");
		Jsonb jsonb = JsonbBuilder.create();  
	 	List<String> logs = jsonb.fromJson(fileJSON, List.class);
	 		
	 	boolean res = model.addNewProduct(logs.get(0), logs.get(1), logs.get(2), logs.get(3));
		
		if(res) {
			return Response.ok().build();
		}
		return Response.status(Response.Status.BAD_REQUEST).entity("501").build();
 	}
	
	
	@DELETE
	@Path("catalogs/medic-catalog/del")
	@Produces("text/plain")
	public Response delProd(@Context HttpServletRequest request, @Context HttpServletResponse response) throws Exception 
 	{            
		String name =  request.getHeader("name").strip();;   
		System.out.println("================" + name + "======================================");
		
		Jsonb jsonb = JsonbBuilder.create();          
		List<String> nameOfProd = jsonb.fromJson(name, List.class);
	 	
	 	boolean res = model.delProduct(nameOfProd.get(0));
		
		if(res) {
			return Response.ok().build();
		}
		return Response.status(Response.Status.BAD_REQUEST).entity("501").build();
 	}
}

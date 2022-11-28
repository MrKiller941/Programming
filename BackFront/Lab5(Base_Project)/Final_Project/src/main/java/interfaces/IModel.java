package interfaces;

import jakarta.enterprise.context.ApplicationScoped;

@ApplicationScoped
public interface IModel {
	boolean checkUserData(String data);
	boolean registrateNewUser(String data);
	String getGameKey(String id_key);
	String getFullCatalog();
}

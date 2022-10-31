package controllers;

import java.sql.SQLException;
import java.util.ArrayList;
import Entity.Med_Product;

public interface IDBController{
	boolean DataIsCorrect(String login, String password) throws SQLException;
	boolean RegistrationNewUser(String login, String password);
	ArrayList<Med_Product> GetGameCatalog() throws SQLException;
	String GetGameKey(String id);
	void ReturnConnectToPool();
}

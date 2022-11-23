package controllers;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;

import Entity.Encryption;
import Entity.ClassFactory;
import Entity.Med_Product;
import interfaces.Pool_IDB;

public class DBController implements IDBController{
	
	private Pool_IDB DBpool = null;
	private Connection conn = null;
	
	private Encryption CP = new Encryption();
	
	
	//============================================================
	private void GetConnectToBase() throws SQLException {
		this.addDBPool(ClassFactory.injectDBPool());
		this.conn = DBpool.getConnection();
	}
	
	//============================================================
	private ResultSet GetSelectResult(String select) throws SQLException{
		this.GetConnectToBase();
		PreparedStatement preparedStatement = this.conn.prepareStatement(select);
        ResultSet resultSet = preparedStatement.executeQuery();
        this.ReturnConnectToPool();
		return resultSet;
	}
	//============================================================
	private void EnterQwery(String qwery) throws SQLException {
		this.GetConnectToBase();
		Statement statement = this.conn.createStatement();
        statement.executeUpdate(qwery);
        this.ReturnConnectToPool();
	}
	//============================================================
	@Override
	public boolean DataIsCorrect(String login, String password) throws SQLException {
		ResultSet result = this.GetSelectResult("Select * from users");
		String a_login;
		String a_password;
		while (result.next()) {
            a_login = result.getString("u_login");
            a_password = result.getString("u_password");
            
            if(a_login.equals(login) && a_password.equals(CP.getCryptPassword(password))) {
            	return true;
            }
        }
		return false;
	}
	//============================================================
	@Override
	public boolean RegistrationNewUser(String login, String password){
		String SELECT_SQL = "insert into users(u_login, u_password) values('"+login +"', '"+CP.getCryptPassword(password)+"')";
		try {
			if(!login.isEmpty() && !password.isEmpty()) {
				this.EnterQwery(SELECT_SQL);
				return true;
			}
			else {
				return false;
			}
		} catch (SQLException e) {
			return false;
		}
	}
	//============================================================
	@Override
	public ArrayList<Med_Product> GetGameCatalog() throws SQLException {
		ResultSet result = this.GetSelectResult("Select * from medicines");
		ArrayList<Med_Product> return_list = new ArrayList<Med_Product>();
		int iter = 0;
		
		while (result.next()){
			Med_Product add_prod = new Med_Product();
			
			add_prod.medic_id = result.getInt("medic_id");
			add_prod.medic_cost = result.getInt("medic_cost");
			add_prod.medic_names = result.getString("medic_names");
			add_prod.medic_count = result.getInt("medic_count");
			add_prod.img = result.getString("img");
			return_list.add(iter, add_prod);
            iter++;
		}
		return return_list;
	}
	
	//============================================================
	@Override
	public String GetGameKey(String id) {
		ResultSet result;
		try {
			result = this.GetSelectResult("Select game_key from game_keys where id = " + id);
			
			String name = null;
			while (result.next()){
				name = result.getString("game_key");
			}
			return name;
		} catch (SQLException e) {
			return "123123123";
		}
	}	
	
	//============================================================
	@Override
	public void ReturnConnectToPool() {
		try {
			this.DBpool.returnConnection(this.conn);
			this.conn = null;
		} catch (SQLException e) {
			System.out.println(e.getMessage());
		}
	}
	
	//============================================================
	
	private void addDBPool(Pool_IDB pool) {
		if(this.DBpool == null) {
			this.DBpool = pool;
		}
	}
	

}

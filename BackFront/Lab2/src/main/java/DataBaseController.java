import java.io.IOException;
import java.lang.reflect.InvocationTargetException;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;

public class DataBaseController {
	private Connection GetConnectToBase()  throws IOException, SQLException, InstantiationException, IllegalAccessException, InvocationTargetException, NoSuchMethodException, SecurityException, ClassNotFoundException{
		 Class.forName("org.postgresql.Driver").getDeclaredConstructor().newInstance();
		 Connection conn = DriverManager.getConnection("jdbc:postgresql://127.0.0.1:5432/Lab2", "postgres", "KENERYAN12");
        return conn;
	}
	//============================================================
	private ResultSet GetSelectResult(String select) throws SQLException{
		Connection this_conn = null;
		try {
			this_conn = this.GetConnectToBase();
			
		} catch (InstantiationException | IllegalAccessException | InvocationTargetException | NoSuchMethodException
				| SecurityException | ClassNotFoundException | IOException | SQLException e) {
			e.printStackTrace();
		}
		
        PreparedStatement preparedStatement = this_conn.prepareStatement(select);
        ResultSet resultSet = preparedStatement.executeQuery();
		return resultSet;
	}
	//============================================================
	private void EnterQwery(String qwery) throws SQLException {
		Connection this_conn = null;
		try {
			this_conn = this.GetConnectToBase();
			
		} catch (InstantiationException | IllegalAccessException | InvocationTargetException | NoSuchMethodException
				| SecurityException | ClassNotFoundException | IOException | SQLException e) {
			e.printStackTrace();
		}
		
        Statement statement = this_conn.createStatement();
        statement.executeUpdate(qwery);
	}
	//============================================================
	public boolean DataIsCorrect(String login, String password) throws SQLException {
		ResultSet result = this.GetSelectResult("Select * from users");
		String a_login;
		String a_password;
		while (result.next()) {
            a_login = result.getString("u_login");
            a_password = result.getString("u_password");
            
            if(a_login.equals(login) && a_password.equals(password)) {
            	return true;
            }
        }
		return false;
	}
	//============================================================
	public boolean RegistrationNewUser(String login, String password){
		String SELECT_SQL = "insert into users(u_login, u_password) values('"+login +"', '"+password+"')";
		try {
			if(!login.isEmpty() && !password.isEmpty()) {
				this.EnterQwery(SELECT_SQL);
				return true;
			}
			else
				return false;
		} catch (SQLException e) {
			return false;
		}
	}
	//============================================================
	public ArrayList<Names_Medic> Medicines() throws SQLException {
		ResultSet result = this.GetSelectResult("Select * from medicines");
		ArrayList<Names_Medic> return_list = new ArrayList<Names_Medic>();
		int iter = 0;
		
		while (result.next()){
			Names_Medic add_medic = new Names_Medic();
			
			add_medic.medic_id = result.getInt("medic_id");
			add_medic.medic_cost = result.getInt("medic_cost");
			add_medic.medic_names = result.getString("medic_names");
			add_medic.medic_count = result.getInt("medic_count");
			add_medic.img = result.getString("img");
			return_list.add(iter, add_medic);
            iter++;
		}
		return return_list;
	}
}

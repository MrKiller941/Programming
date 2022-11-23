package interfaces;

import java.sql.Connection;
import java.sql.SQLException;

public interface Pool_IDB {
	Connection getConnection() throws SQLException;
	void returnConnection(Connection conn) throws SQLException;
}

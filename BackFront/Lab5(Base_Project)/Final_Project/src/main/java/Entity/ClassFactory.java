package Entity;

import controllers.DBController;
import controllers.IDBController;
import interfaces.PoolDB;
import interfaces.Pool_IDB;

public class ClassFactory {
	static public Pool_IDB injectDBPool() {
		return new PoolDB();
	}
	
	static public IDBController injectDBController() {
		return new DBController();
	}
}


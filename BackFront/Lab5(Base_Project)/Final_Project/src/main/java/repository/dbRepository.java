package repository;

import java.util.List;

import jakarta.annotation.Resource;
import jakarta.persistence.EntityManager;
import jakarta.persistence.EntityManagerFactory;
import jakarta.persistence.PersistenceUnit;
import jakarta.transaction.UserTransaction;
import repository.entity.User;
import repository.entity.Medicine;

public class dbRepository {

	@PersistenceUnit(unitName = "Final_Project")
    private EntityManagerFactory entityManagerFactory;
   
    @Resource
    private UserTransaction userTransaction;
    
    private EntityManager entityManager;
    
   
    public void registration(String login, String password) throws Exception {
    	entityManager = entityManagerFactory.createEntityManager();
    	userTransaction.begin();
        entityManager.joinTransaction();
        User person = new User();
	    person.setULogin(login);		 
	    person.setUPassword(password);
	    entityManager.persist(person);
	    userTransaction.commit();
    }
    
    
    public User authorisation(String login, String password) throws Exception {
		entityManager = entityManagerFactory.createEntityManager();
		userTransaction.begin();
		entityManager.joinTransaction();
		List<User> users = entityManager.createQuery("SELECT u FROM User u",User.class).getResultList();     
		
		for(User user : users) {
			if(user.getULogin().equals(login) && user.getUPassword().equals(password)) {
				userTransaction.commit();
				return user;
			}
		}
		userTransaction.commit();
		return null;
    }

    
    public List<Medicine> getCatalog() throws Exception {
    	entityManager = entityManagerFactory.createEntityManager();
		userTransaction.begin();
		
		entityManager.joinTransaction();
		List<Medicine> products = entityManager.createQuery("SELECT m FROM Medicine m",Medicine.class).getResultList();    
		userTransaction.commit();
		return products;
    }
    
}

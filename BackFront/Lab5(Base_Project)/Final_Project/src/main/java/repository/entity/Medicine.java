package repository.entity;

import java.io.Serializable;

import jakarta.persistence.Column;
import jakarta.persistence.Entity;
import jakarta.persistence.NamedQuery;
import jakarta.persistence.Table;



@Entity
@Table(name="medicines")
@NamedQuery(name="Medicine.findAll", query="SELECT m FROM Medicine m")
public class Medicine implements Serializable {
	private static final long serialVersionUID = 1L;

	private String img;

	@Column(name="medic_cost")
	private Integer medicCost;

	@Column(name="medic_count")
	private String medicCount;

	@Column(name="medic_id")
	private Integer medicId;

	@Column(name="medic_names")
	private String medicNames;

	public Medicine() {
	}

	public String getImg() {
		return this.img;
	}

	public void setImg(String img) {
		this.img = img;
	}

	public Integer getMedicCost() {
		return this.medicCost;
	}

	public void setMedicCost(Integer medicCost) {
		this.medicCost = medicCost;
	}

	public String getMedicCount() {
		return this.medicCount;
	}

	public void setMedicCount(String medicCount) {
		this.medicCount = medicCount;
	}

	public Integer getMedicId() {
		return this.medicId;
	}

	public void setMedicId(Integer medicId) {
		this.medicId = medicId;
	}

	public String getMedicNames() {
		return this.medicNames;
	}

	public void setMedicNames(String medicNames) {
		this.medicNames = medicNames;
	}

}
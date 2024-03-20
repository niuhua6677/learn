package utils;

public class Brand {
    //id主键
    private Integer id;
    private String brand_name;
    private String company_name;
    private String description;
    private Integer ordered;

    public Brand() {
    }

    public Brand(Integer id, String brandName, String companyName, String description, Integer ordered) {
        this.id = id;
        this.brand_name = brandName;
        this.company_name = companyName;
        this.description = description;
        this.ordered = ordered;
    }

    public Integer getId() {
        return id;
    }

    public void setId(Integer id) {
        this.id = id;
    }

    public String getBrandName() {
        return brand_name;
    }

    public void setBrandName(String brandName) {
        this.brand_name = brandName;
    }

    public String getCompanyName() {
        return company_name;
    }

    public void setCompanyName(String companyName) {
        this.company_name = companyName;
    }

    public String getDescription() {
        return description;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public Integer getOrdered() {
        return ordered;
    }

    public void setOrdered(Integer ordered) {
        this.ordered = ordered;
    }

    @Override
    public String toString() {
        return "Brand{" +
                "id=" + id +
                ", brandName='" + brand_name + '\'' +
                ", companyName='" + company_name + '\'' +
                ", description='" + description + '\'' +
                ", ordered=" + ordered +
                '}';
    }
}

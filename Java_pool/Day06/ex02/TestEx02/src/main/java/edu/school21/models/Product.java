package edu.school21.models;

import java.util.Objects;

public class Product {
    private Long        id;
    private String      name;
    private Integer     coast;

    public Product() {
    }

    public Product(Long id, String name, int coast) {
        this.id = id;
        this.name = name;
        this.coast = coast;
    }

    /* getters */

    public Long getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    public Integer getCoast() {
        return coast;
    }

    /* setters */

    public void setId(Long id) {
        this.id = id;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setCoast(Integer coast) {
        this.coast = coast;
    }

    /* override functions */

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Product product = (Product) o;
        return id.equals(product.id) && name.equals(product.name) && coast.equals(product.coast);
    }

    @Override
    public int hashCode() {
        return Objects.hash(id, name, coast);
    }

    @Override
    public String toString() {
        return "Product{" +
                "id=" + id +
                ", name='" + name + '\'' +
                ", coast='" + coast + '\'' +
                '}';
    }
}

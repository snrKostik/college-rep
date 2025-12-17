using Microsoft.EntityFrameworkCore;
using Prob_3.Models;

namespace Prob_3.Data;

public class AppDbContext : DbContext {
  public DbSet<Order> Orders => Set<Order>();
  public DbSet<OrderItem> OrderItems => Set<OrderItem>();

  protected override void OnConfiguring(DbContextOptionsBuilder options) {
    options.UseSqlite("Data Source=orders.db");
  }
}

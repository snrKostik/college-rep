using Microsoft.EntityFrameworkCore;
using Prob_2.Models;

namespace Prob_2.Data;

public class AppDbContext : DbContext {
  public DbSet<Product> Products => Set<Product>();

  protected override void OnConfiguring(DbContextOptionsBuilder options) {
    options.UseSqlite("Data Source=app.db");
  }
}

using System;
using System.Collections.Generic;
using System.Linq;
using Microsoft.EntityFrameworkCore;
using Microsoft.Extensions.Logging;

namespace MyApp;

public class LibraryContext : DbContext {
  public DbSet<Author> Authors { get; set; }
  public DbSet<Book> Books { get; set; }

  protected override void
  OnConfiguring(DbContextOptionsBuilder optionsBuilder) {
    optionsBuilder.UseSqlite("Data Source=library.db;");
  }

  protected override void OnModelCreating(ModelBuilder modelBuilder) {
    modelBuilder.Entity<Book>()
        .HasOne(b => b.Author)  // книга 1 автор
        .WithMany(a => a.Books) // автор много книг
        .HasForeignKey(b => b.AuthorId);
  }
}

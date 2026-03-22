// Добавление новой задачи
$("#addTask").click(function() {
    $("#taskList").append('<li>Новая задача <button class="delete-btn">Удалить</button></li>');
});

// Удаление задачи (Делегирование события на родительский <ul>)
$("#taskList").on("click", ".delete-btn", function() {
    $(this).parent().remove();
});

// Открытие модалки
$("#openModal").click(function() {
    $("#myModal").fadeIn();
});

// Закрытие по крестику ИЛИ по клику на затемненный фон
$("#myModal, #closeModal").click(function(e) {
    // Если клик был именно по фону (#myModal) или по кнопке закрытия, а не внутри окна
    if (e.target === this) {
        $("#myModal").fadeOut();
    }
});

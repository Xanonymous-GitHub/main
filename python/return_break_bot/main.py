from telegram.ext import Updater, CommandHandler


def hello(bot, update):
    update.message.reply_text('hello, {}'.format(
        update.message.from_user.first_name))


updater = Updater('883266185:AAGFniLJA7BDstTJheKDZZc9Fh-5U3jHhwg')
updater.dispatcher.add_handler(CommandHandler('hello', hello))
updater.start_polling()
updater.idle()

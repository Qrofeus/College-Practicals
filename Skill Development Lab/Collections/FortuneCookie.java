package Collections;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Random;
import java.util.Scanner;

public class FortuneCookie {
    public static ArrayList<String> cookies = new ArrayList<>();

    public static void main(String[] args) {
        cookieQuotes();
        Scanner scan = new Scanner(System.in);
        Random rnd = new Random();
        String input;
        while (true) {
            System.out.println("----------\nCrack a cookie?");
            input = scan.next();
            if (!input.toLowerCase().equals("yes")) {
                break;
            }
            System.out.println(cookies.get(rnd.nextInt(cookies.size())) + "\n");
        }
    }

    public static void cookieQuotes() {
        String cookiesStrings = "A beautiful, smart, and loving person will be coming into your life.\n" +
                "A dubious friend may be an enemy in camouflage.\n" +
                "A faithful friend is a strong defense.\n" +
                "A feather in the hand is better than a bird in the air.\n" +
                "A fresh start will put you on your way.\n" +
                "A friend asks only for your time not your money.\n" +
                "A friend is a present you give yourself.\n" +
                "A gambler not only will lose what he has, but also will lose what he doesn’t have.\n" +
                "A golden egg of opportunity falls into your lap this month.\n" +
                "A good friendship is often more important than a passionate romance.\n" +
                "A good time to finish up old tasks.\n" +
                "A hunch is creativity trying to tell you something.\n" +
                "A lifetime friend shall soon be made.\n" +
                "A lifetime of happiness lies ahead of you.\n" +
                "A light heart carries you through all the hard times.\n" +
                "A new perspective will come with the new year.\n" +
                "A person is never to old to learn.\n" +
                "A person of words and not deeds is like a garden full of weeds.\n" +
                "A pleasant surprise is waiting for you.\n" +
                "A short pencil is usually better than a long memory any day.\n" +
                "A small donation is called for. It’s the right thing to do.\n" +
                "A smile is your personal welcome mat.\n" +
                "A smooth long journey! Great expectations.\n" +
                "A soft voice may be awfully persuasive.\n" +
                "A truly rich life contains love and art in abundance.\n" +
                "Accept something that you cannot change, and you will feel better.\n" +
                "Adventure can be real happiness.\n" +
                "Advice is like kissing. It costs nothing and is a pleasant thing to do.\n" +
                "Advice, when most needed, is least heeded.\n" +
                "All the effort you are making will ultimately pay off.\n" +
                "All the troubles you have will pass away very quickly.\n" +
                "All will go well with your new project.\n" +
                "All your hard work will soon pay off.\n" +
                "Allow compassion to guide your decisions.\n" +
                "An acquaintance of the past will affect you in the near future.\n" +
                "An agreeable romance might begin to take on the appearance.\n" +
                "An important person will offer you support.\n" +
                "An inch of time is an inch of gold.\n" +
                "Any decision you have to make tomorrow is a good decision.\n" +
                "At the touch of love, everyone becomes a poet.\n" +
                "Be careful or you could fall for some tricks today.\n" +
                "Beauty in its various forms appeals to you.\n" +
                "Because you demand more from yourself, others respect you deeply.\n" +
                "Believe in yourself and others will too.\n" +
                "Believe it can be done.\n" +
                "Better ask twice than lose yourself once.\n" +
                "Bide your time, for success is near.\n" +
                "Carve your name on your heart and not on marble.\n" +
                "Change is happening in your life, so go with the flow!\n" +
                "Competence like yours is underrated.\n" +
                "Congratulations! You are on your way.\n" +
                "Could I get some directions to your heart?\n" +
                "Courtesy begins in the home.\n" +
                "Courtesy is contagious.\n" +
                "Curiosity kills boredom. Nothing can kill curiosity.\n" +
                "Dedicate yourself with a calm mind to the task at hand.\n" +
                "Depart not from the path which fate has you assigned.\n" +
                "Determination is what you need now.\n" +
                "Diligence and modesty can raise your social status.\n" +
                "Disbelief destroys the magic.\n" +
                "Distance yourself from the vain.\n" +
                "Do not be intimidated by the eloquence of others.\n" +
                "Do not demand for someone’s soul if you already got his heart.\n" +
                "Do not let ambitions overshadow small success.\n" +
                "Do not make extra work for yourself.\n" +
                "Do not underestimate yourself. Human beings have unlimited potentials.\n" +
                "Do you know that the busiest person has the largest amount of time?\n" +
                "Don’t be discouraged, because every wrong attempt discarded is another step forward.\n" +
                "Don’t confuse recklessness with confidence.\n" +
                "Don’t just spend time. Invest it.\n" +
                "Don’t just think, act!\n" +
                "Don’t let friends impose on you, work calmly and silently.\n" +
                "Don’t let the past and useless detail choke your existence.\n" +
                "Don’t let your limitations overshadow your talents.\n" +
                "Don’t worry; prosperity will knock on your door soon.\n" +
                "Each day, compel yourself to do something you would rather not do.\n" +
                "Education is the ability to meet life’s situations.\n" +
                "Embrace this love relationship you have!\n" +
                "Emulate what you admire in your parents.\n" +
                "Emulate what you respect in your friends.\n" +
                "Every flower blooms in its own sweet time.\n" +
                "Every wise man started out by asking many questions.\n" +
                "Everyday in your life is a special occasion.\n" +
                "Everywhere you choose to go, friendly faces will greet you.\n" +
                "Expect much of yourself and little of others.\n" +
                "Failure is the chance to do better next time.\n" +
                "Failure is the path of lease persistence.\n" +
                "Fear and desire – two sides of the same coin.\n" +
                "Fearless courage is the foundation of victory.\n" +
                "Feeding a cow with roses does not get extra appreciation.\n" +
                "First think of what you want to do; then do what you have to do.\n" +
                "Follow the middle path. Neither extreme will make you happy.\n" +
                "For hate is never conquered by hate. Hate is conquered by love.\n" +
                "For the things we have to learn before we can do them, we learn by doing them.\n" +
                "Fortune Not Found: Abort, Retry, Ignore?\n" +
                "From listening comes wisdom and from speaking repentance.\n" +
                "From now on your kindness will lead you to success.\n" +
                "Get your mind set – confidence will lead you on.\n" +
                "Get your mind set…confidence will lead you on.\n" +
                "Go for the gold today! You’ll be the champion of whatever.\n" +
                "Go take a rest; you deserve it.\n" +
                "Good news will be brought to you by mail.\n" +
                "Good news will come to you by mail.\n" +
                "Good to begin well, better to end well.\n" +
                "Happiness begins with facing life with a smile and a wink.\n" +
                "Happiness will bring you good luck.\n" +
                "Happy life is just in front of you.\n" +
                "Hard words break no bones, fine words butter no parsnips.\n" +
                "Have a beautiful day.\n" +
                "He who expects no gratitude shall never be disappointed.\n" +
                "He who knows he has enough is rich.\n" +
                "He who knows others is wise. He who knows himself is enlightened.\n" +
                "Help! I’m being held prisoner in a chinese bakery!\n" +
                "How many of you believe in psycho-kinesis? Raise my hand.\n" +
                "How you look depends on where you go.\n" +
                "I learn by going where I have to go.\n" +
                "If a true sense of value is to be yours it must come through service.\n" +
                "If certainty were truth, we would never be wrong.\n" +
                "If you continually give, you will continually have.\n" +
                "If you look in the right places, you can find some good offerings.\n" +
                "If you think you can do a thing or think you can’t do a thing, you’re right.\n" +
                "If you wish to see the best in others, show the best of yourself.\n" +
                "If your desires are not extravagant, they will be granted.\n" +
                "If your desires are not to extravagant they will be granted.\n" +
                "If you’re feeling down, try throwing yourself into your work.\n" +
                "Imagination rules the world.\n" +
                "In order to take, one must first give.\n" +
                "In the end all things will be known.\n" +
                "In this world of contradiction, It’s better to be merry than wise.\n" +
                "It could be better, but its good enough.\n" +
                "It is better to be an optimist and proven a fool than to be a pessimist and be proven right.\n" +
                "It is better to deal with problems before they arise.\n" +
                "It is honorable to stand up for what is right, however unpopular it seems.\n" +
                "It is worth reviewing some old lessons.\n" +
                "It takes courage to admit fault.\n" +
                "It’s not the amount of time you devote, but what you devote to the time that counts.\n" +
                "It’s time to get moving. Your spirits will lift accordingly.\n" +
                "Keep your face to the sunshine and you will never see shadows.\n" +
                "Let the world be filled with tranquility and goodwill.\n" +
                "Like the river flow into the sea. Something are just meant to be.\n" +
                "Listen not to vain words of empty tongue.\n" +
                "Listen to everyone. Ideas come from everywhere.\n" +
                "Living with a commitment to excellence shall take you far.\n" +
                "Long life is in store for you.\n" +
                "Love is a warm fire to keep the soul warm.\n" +
                "Love is like sweet medicine, good to the last drop.\n" +
                "Love lights up the world.\n" +
                "Love truth, but pardon error.\n" +
                "Man is born to live and not prepared to live.\n" +
                "Man’s mind, once stretched by a new idea, never regains it’s original dimensions.\n" +
                "Many will travel to hear you speak.\n" +
                "Meditation with an old enemy is advised.\n" +
                "Miles are covered one step at a time.\n" +
                "Nature, time and patience are the three great physicians.\n" +
                "Never fear! The end of something marks the start of something new.\n" +
                "New ideas could be profitable.\n" +
                "New people will bring you new realizations, especially about big issues.\n" +
                "No one can walk backwards into the future.\n" +
                "Nothing is more difficult, and therefore more precious, than to be able to decide.\n" +
                "Now is a good time to buy stock.\n" +
                "Now is the time to go ahead and pursue that love interest!\n" +
                "Now is the time to try something new.\n" +
                "Observe all men, but most of all yourself.\n" +
                "One can never fill another’s shoes, rather he must outgrow the old shoes.\n" +
                "One of the first things you should look for in a problem is its positive side.\n" +
                "Others can help you now.\n" +
                "Pennies from heaven find their way to your doorstep this year!\n" +
                "People are attracted by your Delicate[sic] features.\n" +
                "People find it difficult to resist your persuasive manner.\n" +
                "Perhaps you’ve been focusing too much on saving.\n" +
                "Physical activity will dramatically improve your outlook today.\n" +
                "Pick battles big enough to matter, small enough to win.\n" +
                "Place special emphasis on old friendship.\n" +
                "Po Says: Pandas like eating bamboo, but I prefer mine dipped in chocolate.\n" +
                "Practice makes perfect.\n" +
                "Protective measures will prevent costly disasters.\n" +
                "Put your mind into planning today. Look into the future.\n" +
                "Remember the birthday but never the age.\n" +
                "Remember to share good fortune as well as bad with your friends.\n" +
                "Rest has a peaceful effect on your physical and emotional health.\n" +
                "Resting well is as important as working hard.\n" +
                "Romance moves you in a new direction.\n" +
                "Savor your freedom – it is precious.\n" +
                "Say hello to others. You will have a happier day.\n" +
                "Self-knowledge is a life long process.\n" +
                "Share your joys and sorrows with your family.\n" +
                "Sift through your past to get a better idea of the present.\n" +
                "Sloth makes all things difficult; industry all easy.\n" +
                "Small confidences mark the onset of a friendship.\n" +
                "Society prepares the crime; the criminal commits it.\n" +
                "Someone you care about seeks reconciliation.\n" +
                "Soon life will become more interesting.\n" +
                "Stand tall. Don’t look down upon yourself.\n" +
                "Staying close to home is going to be best for your morale today\n" +
                "Stop searching forever, happiness is just next to you.\n" +
                "Strong reasons make strong actions.\n" +
                "Success is a journey, not a destination.\n" +
                "Success is failure turned inside out.\n" +
                "Success is going from failure to failure without loss of enthusiasm.\n" +
                "Swimming is easy. Stay floating is hard.\n" +
                "Take care and sensitivity you show towards others will return to you.\n" +
                "Take the high road.\n" +
                "Technology is the art of arranging the world so we do not notice it.\n" +
                "The austerity you see around you covers the richness of life like a veil.\n" +
                "The best prediction of future is the past.\n" +
                "The change you started already have far-reaching effects. Be ready.\n" +
                "The change you started already have far-reaching effects. Be ready.\n" +
                "The first man gets the oyster, the second man gets the shell.\n" +
                "The greatest achievement in life is to stand up again after falling.\n" +
                "The harder you work, the luckier you get.\n" +
                "The night life is for you.\n" +
                "The one that recognizes the illusion does not act as if it is real.\n" +
                "The only people who never fail are those who never try.\n" +
                "The person who will not stand for something will fall for anything.\n" +
                "The philosophy of one century is the common sense of the next.\n" +
                "The saints are the sinners who keep on trying.\n" +
                "The secret to good friends is no secret to you.\n" +
                "The small courtesies sweeten life, the greater ennoble it.\n" +
                "The smart thing to do is to begin trusting your intuitions.\n" +
                "The strong person understands how to withstand substantial loss.\n" +
                "The sure way to predict the future is to invent it.\n" +
                "The truly generous share, even with the undeserving.\n" +
                "The value lies not within any particular thing, but in the desire placed on that thing.\n" +
                "The weather is wonderful.\n" +
                "There is no mistake so great as that of being always right.\n" +
                "There is no wisdom greater than kindness.\n" +
                "There is not greater pleasure than seeing your lived ones prosper.\n" +
                "There’s no such thing as an ordinary cat.\n" +
                "Things don’t just happen; they happen just.\n" +
                "Those who care will make the effort.\n" +
                "Time and patience are called for many surprises await you!.\n" +
                "Time is precious, but truth is more precious than time\n" +
                "To know oneself, one should assert oneself.\n" +
                "To the world you may be one person, but to one person you may be the world.\n" +
                "Today is the conserve yourself, as things just won’t budge.\n" +
                "Today, your mouth might be moving but no one is listening.\n" +
                "Tonight you will be blinded by passion.\n" +
                "Use your eloquence where it will do the most good.\n" +
                "We first make our habits, and then our habits make us.\n" +
                "Welcome change.\n" +
                "“Welcome” is a powerful word.\n" +
                "Well done is better than well said.\n" +
                "What’s hidden in an empty box?\n" +
                "What’s yours in mine, and what’s mine is mine.\n" +
                "When more become too much. It’s same as being not enough.\n" +
                "When your heart is pure, your mind is clear.\n" +
                "Wish you happiness.\n" +
                "With age comes wisdom.\n" +
                "You always bring others happiness.\n" +
                "You are a person of another time.\n" +
                "You are a talented storyteller.\n" +
                "You are admired by everyone for your talent and ability.\n" +
                "You are almost there.\n" +
                "You are busy, but you are happy.\n" +
                "You are generous to an extreme and always think of the other fellow.\n" +
                "You are going to have some new clothes.\n" +
                "You are in good hands this evening.\n" +
                "You are interested in higher education, whether material or spiritual.\n" +
                "You are modest and courteous.\n" +
                "You are never selfish with your advice or your help.\n" +
                "You are next in line for promotion in your firm.\n" +
                "You are offered the dream of a lifetime. Say yes!\n" +
                "You are open-minded and quick to make new friends.\n" +
                "You are solid and dependable.\n" +
                "You are soon going to change your present line of work.\n" +
                "You are talented in many ways.\n" +
                "You are the master of every situation.\n" +
                "You are very expressive and positive in words, act and feeling.\n" +
                "You are working hard.\n" +
                "You begin to appreciate how important it is to share your personal beliefs.\n" +
                "You can keep a secret.\n" +
                "You can see a lot just by looking.\n" +
                "You can’t steal second base and keep your foot on first.\n" +
                "You desire recognition and you will find it.\n" +
                "You have a deep appreciation of the arts and music.\n" +
                "You have a deep interest in all that is artistic.\n" +
                "You have a friendly heart and are well admired.\n" +
                "You have a shrewd knack for spotting insincerity.\n" +
                "You have a yearning for perfection.\n" +
                "You have an active mind and a keen imagination.\n" +
                "You have an ambitious nature and may make a name for yourself.\n" +
                "You have an unusual equipment for success, use it properly.\n" +
                "You have exceeded what was expected.\n" +
                "You have had a good start. Work harder!\n" +
                "You have the power to write your own fortune.\n" +
                "You have yearning for perfection.\n" +
                "You know where you are going and how to get there.\n" +
                "You look pretty.\n" +
                "You love challenge.\n" +
                "You love chinese food.\n" +
                "You make people realize that there exist other beauties in the world.\n" +
                "You never hesitate to tackle the most difficult problems.\n" +
                "You never know who you touch.\n" +
                "You only treasure what you lost.\n" +
                "You seek to shield those you love and like the role of provider.\n" +
                "You should be able to make money and hold on to it.\n" +
                "You should be able to undertake and complete anything.\n" +
                "You should pay for this check. Be generous.\n" +
                "You understand how to have fun with others and to enjoy your solitude.\n" +
                "You will always be surrounded by true friends.\n" +
                "You will always get what you want through your charm and personality.\n" +
                "You will always have good luck in your personal affairs.\n" +
                "You will be a great success both in the business world and society.\n" +
                "You will be blessed with longevity.\n" +
                "You will be pleasantly surprised tonight.\n" +
                "You will be sharing great news with all the people you love.\n" +
                "You will be successful in your work.\n" +
                "You will be traveling and coming into a fortune.\n" +
                "You will be unusually successful in business.\n" +
                "You will become a great philanthropist in your later years.\n" +
                "You will become more and more wealthy.\n" +
                "You will enjoy good health.\n" +
                "You will enjoy good health; you will be surrounded by luxury.\n" +
                "You will find great contentment in the daily, routine activities.\n" +
                "You will have a fine capacity for the enjoyment of life.\n" +
                "You will have gold pieces by the bushel.\n" +
                "You will inherit a large sum of money.\n" +
                "You will make change for the better.\n" +
                "You will soon be surrounded by good friends and laughter.\n" +
                "You will take a chance in something in near future.\n" +
                "You will travel far and wide, both pleasure and business.\n" +
                "You will travel far and wide,both pleasure and business.\n" +
                "Your abilities are unparalleled.\n" +
                "Your ability is appreciated.\n" +
                "Your ability to juggle many tasks will take you far.\n" +
                "Your biggest virtue is your modesty.\n" +
                "Your character can be described as natural and unrestrained.\n" +
                "Your difficulties will strengthen you.\n" +
                "Your dreams are never silly; depend on them to guide you.\n" +
                "Your dreams are worth your best efforts to achieve them.\n" +
                "Your energy returns and you get things done.\n" +
                "Your family is young, gifted and attractive.\n" +
                "Your first love has never forgotten you.\n" +
                "Your goal will be reached very soon.\n" +
                "Your happiness is before you, not behind you! Cherish it.\n" +
                "Your hard work will payoff today.\n" +
                "Your heart will always make itself known through your words.\n" +
                "Your home is the center of great love.\n" +
                "Your ideals are well within your reach.\n" +
                "Your infinite capacity for patience will be rewarded sooner or later.\n" +
                "Your leadership qualities will be tested and proven.\n" +
                "Your life will be happy and peaceful.\n" +
                "Your life will get more and more exciting.\n" +
                "Your love life will be happy and harmonious.\n" +
                "Your love of music will be an important part of your life.\n" +
                "Your loyalty is a virtue, but not when it’s wedded with blind stubbornness.\n" +
                "Your mentality is alert, practical, and analytical.\n" +
                "Your mind is creative, original and alert.\n" +
                "Your mind is your greatest asset.\n" +
                "Your moods signal a period of change.\n" +
                "Your quick wits will get you out of a tough situation.\n" +
                "Your reputation is your wealth.\n" +
                "Your success will astonish everyone.\n" +
                "Your talents will be recognized and suitably rewarded.\n" +
                "Your work interests can capture the highest status or prestige.";
        Collections.addAll(cookies, cookiesStrings.split("\n"));
    }
}

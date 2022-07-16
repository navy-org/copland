COPLAND = $(BUILD)/libcopland.a
COPLAND_BUILD = $(BUILD)/copland

COPLAND_SRC = $(wildcard src/copland/*.c)
COPLAND_OBJ := $(patsubst %, $(COPLAND_BUILD)/%.o, $(COPLAND_SRC))
COPLAND_DEPENDENCIES += $(COPLAND:.o=.d)

$(COPLAND_BUILD)/%.c.o: %.c
	@$(MKCWD)
	$(CC) -c -o $@ $< $(CFLAGS)

$(COPLAND): $(COPLAND_OBJ)
	@$(MKCWD)
	$(AR) $(ARFLAGS) $@ $<
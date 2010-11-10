use 5.006;
use ExtUtils::MakeMaker;
# See lib/ExtUtils/MakeMaker.pm for details of how to influence the contents
# of the Makefile that is written.
WriteMakefile(
    'NAME'              => 'Purple',
    'VERSION_FROM'      => './Purple.pm', # finds $VERSION
    'PREREQ_PM'         => {}, # e.g., Module::Name => 1.1
    ($] >= 5.005 ? ## Add these new keywords supported since 5.005
      (ABSTRACT_FROM    => './Purple.pm', # finds $ABSTRACT
       AUTHOR           => 'Purple <http://pidgin.im/>') : ()),
    'DEFINE'            => '-Wall  -DPURPLE_DISABLE_DEPRECATED -DPIDGIN_DISABLE_DEPRECATED -DFINCH_DISABLE_DEPRECATED -DGNT_DISABLE_DEPRECATED -Waggregate-return -Wcast-align -Wdeclaration-after-statement -Wendif-labels -Werror-implicit-function-declaration -Wextra -Wno-sign-compare -Wno-unused-parameter -Wformat-security -Werror=format-security -Winit-self -Wmissing-declarations -Wmissing-noreturn -Wmissing-prototypes -Wpointer-arith -Wundef -Wp,-D_FORTIFY_SOURCE=2',
    'INC'               => '-I. -I. -I../../../.. -I../../../../libpurple -pthread -I/usr/include/glib-2.0 -I/usr/lib/glib-2.0/include  ',
    'OBJECT'            => '$(O_FILES)', # link all the C files too
#    'OPTIMIZE'          => '-g', # For debugging
    'INSTALLDIRS'          => 'vendor',
    'INSTALL_BASE'         => '$(prefix)',
    'INSTALLVENDORARCH'    => '$(libdir)/purple-$(PURPLE_MAJOR_VERSION)/perl',
    'INSTALLVENDORMAN3DIR' => '$(mandir)/man3',
    'macro'                => {
        'prefix'               => '/usr/local',
        'exec_prefix'          => '${prefix}',
        'libdir'               => '${exec_prefix}/lib',
        'mandir'               => '${datarootdir}/man',
        'datarootdir'          => '${prefix}/share',
        'PURPLE_MAJOR_VERSION' => '2',
    },
);
